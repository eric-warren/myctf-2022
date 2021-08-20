#include <stdio.h>
#include <wchar.h>

wchar_t* flag = L"flag{1t_1s_v3ry_v3ry_w1d3}";

int main() {
  wchar_t buffer[80];

  wprintf(L"We will check your flag.\nSo give it to me> ");
  fgetws(buffer, sizeof(buffer) / sizeof(wchar_t),stdin);

  if(wcscmp(flag, buffer) == 0) {
    fputws (L"Correct!",stdout);
  }
  return 0; 
}