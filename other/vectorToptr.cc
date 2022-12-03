#include <stdio.h>
#include <memory>
#include <vector>

// @param data: pcm 格式编码，单通道，16 位量化
// @param data_size: data 长度
void convert_pcm_to_float(const char* data, int data_size,
                          float* float_data, int* float_data_size) {
  // float_data = reinterpret_cast<const float*>(data);
  std::vector<float> tmp(reinterpret_cast<const float*>(data),
                         reinterpret_cast<const float*>(data) + data_size / sizeof(float));
  float_data = tmp.data();
  (*float_data_size) = data_size / sizeof(float);
}

int main() {
  // TODO(case 1): 数组存储 pcm 数据，指针存储 float 数据，调用 convert_pcm_to_float
  const char array_data[4] = {0x01, 0x02, 0x03, 0x04};
  float* float_array_data = (float *)malloc(2 * sizeof(float));
  int float_array_size = 0;
  convert_pcm_to_float(array_data, sizeof(array_data),
                       float_array_data, &float_array_size);
  free(float_array_data);
  // TODO(case 2): vector 存储 pcm 数据，指针存储 float 数据，调用 convert_pcm_to_float
  std::vector<char> vec_data = {0x01, 0x02, 0x03, 0x04};
  float_array_data = (float *)malloc(2 * sizeof(float));
  convert_pcm_to_float(vec_data.data(), vec_data.size(),
                       float_array_data, &float_array_size);
  free(float_array_data);
  // TODO(case 3): vector 存储 pcm 数据，vector 存储 float 数据，调用 convert_pcm_to_float
  std::vector<float> vec_float;
  convert_pcm_to_float(vec_data.data(), vec_data.size(),
                       vec_float.data(), &float_array_size);
  return 0;
}