#include <nan.h>

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

#include <list>

#include <stdio.h>
#include <stdlib.h>
#include <psapi.h>
#include <string>

#include <sstream>

#include <vector>

#include <iostream>
#include <fstream>

using namespace std;

using v8::Local;
using v8::FunctionTemplate;
using v8::Number;
using v8::Handle;
using v8::Object;
using v8::String;
using v8::Array;

using Nan::GetFunction;
using Nan::New;
using Nan::Set;
using Nan::True;
using Nan::False;
using Nan::Export;

NAN_METHOD(disableZIndex) {
  Local<Object> buffer = (info[0]->ToObject());
  char* pointer = node::Buffer::Data(buffer);
  void* pointerVoid = static_cast<void*>(pointer);
  LPARAM lParam = *((LPARAM*)pointerVoid);
  LPWINDOWPOS windowPos = (LPWINDOWPOS)lParam;
  windowPos->flags |= SWP_NOZORDER;
  windowPos->flags |= SWP_NOMOVE;
  windowPos->hwndInsertAfter = HWND_BOTTOM;
}

NAN_MODULE_INIT(init) {
  NAN_EXPORT(target, disableZIndex);
}

NODE_MODULE(windows, init)