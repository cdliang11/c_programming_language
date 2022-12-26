
#include <stdio.h>
#include <unistd.h>

// 构建块
typedef long Align;   // 边界对齐类型

union header {
  struct {
    union header *ptr;  // 指向下一个块
    unsigned size;  // 块大小
  } s;
  Align x;
};

typedef union header Header;

static Header base;  // 表示空闲链表的头部
static Header *freep = NULL;

// free

void free(void *ap) {
  Header *bp, *p;
  bp = (Header*)ap - 1;  // 指向块头
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      // 被释放的块在链表的开头或者结尾
      break;
  }
  if (bp + bp->s.size == p->s.ptr) {
    // 与上一个块合并
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
  if (p + p->s.size == bp) {
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}

// morecore 用于向操作系统请求空闲空间
#define NALLOC 1024  // 最小申请单元数

static Header *morecore(unsigned nu) {
  // 调用sbrk 返回一个指针，该指针指向n个字节的存储空间
  char *cp;
  Header *up;
  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char*) - 1)
    return NULL;
  up = (Header*) cp;
  up->s.size = nu;
  free((void*)(up+1));
  return freep;
}

// malloc


void *mymalloc(unsigned nbytes) {
  Header *p, *prevp;
  Header *morecore(unsigned);  //向系统申请更多的空间
  unsigned nunits;
  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prevp = freep) == NULL) {
    // 第一次调用malloc时，freep=NULL
    // 系统将创建一个退化的空闲链表
    // 只包含一个大小为0的块，且该块指向自己
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  // 请求空闲空间的时候，将搜索空闲块链表
  // 搜索从上次找到空闲块的地方(freep)开始
  // 如果找到的块太大，将其尾部返回给用户，这样初始块的头部只需修改size字段即可
  for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) {
      // 足够大
      if (p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
      else {
        // 分配末尾部分
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if (p == freep) {
        if ((p = morecore(nunits)) == NULL) {
          return NULL;  // 没有剩余空间
        }
    }
  }
}

int main() {
  int* p = mymalloc(sizeof(int));
  free(p);
  return 0;
}