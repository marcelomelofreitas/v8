// Copyright 2016 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_REGEXP_REGEXP_UTILS_H_
#define V8_REGEXP_REGEXP_UTILS_H_

#include "src/objects.h"

namespace v8 {
namespace internal {

// Helper methods for C++ regexp builtins.
class RegExpUtils : public AllStatic {
 public:
  // Last match info accessors.
  static Handle<Object> GetLastMatchField(Isolate* isolate,
                                          Handle<JSObject> match_info,
                                          int index);
  static void SetLastMatchField(Isolate* isolate, Handle<JSObject> match_info,
                                int index, Handle<Object> value);
  static int GetLastMatchNumberOfCaptures(Isolate* isolate,
                                          Handle<JSObject> match_info);
  static Handle<String> GetLastMatchSubject(Isolate* isolate,
                                            Handle<JSObject> match_info);
  static Handle<Object> GetLastMatchInput(Isolate* isolate,
                                          Handle<JSObject> match_info);
  static int GetLastMatchCapture(Isolate* isolate, Handle<JSObject> match_info,
                                 int i);
  static Handle<String> GenericCaptureGetter(Isolate* isolate,
                                             Handle<JSObject> match_info,
                                             int capture, bool* ok = nullptr);

  // Last index (RegExp.lastIndex) accessors.
  static MaybeHandle<Object> SetLastIndex(Isolate* isolate,
                                          Handle<JSReceiver> regexp, int value);
  static MaybeHandle<Object> GetLastIndex(Isolate* isolate,
                                          Handle<JSReceiver> recv);

  // ES#sec-regexpexec Runtime Semantics: RegExpExec ( R, S )
  static MaybeHandle<Object> RegExpExec(Isolate* isolate,
                                        Handle<JSReceiver> regexp,
                                        Handle<String> string,
                                        Handle<Object> exec);

  // ES#sec-isregexp IsRegExp ( argument )
  // Includes checking of the match property.
  static Maybe<bool> IsRegExp(Isolate* isolate, Handle<Object> object);

  // Checks whether exec is identical to the initial RegExp.prototype.exec.
  static bool IsBuiltinExec(Handle<Object> exec);

  // Generic index increment methods respecting unicode surrogate pairs.
  static int AdvanceStringIndex(Isolate* isolate, Handle<String> string,
                                int index, bool unicode);
  static MaybeHandle<Object> SetAdvancedStringIndex(Isolate* isolate,
                                                    Handle<JSReceiver> regexp,
                                                    Handle<String> string,
                                                    bool unicode);
};

}  // namespace internal
}  // namespace v8

#endif  // V8_REGEXP_REGEXP_UTILS_H_
