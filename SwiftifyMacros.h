//
//  SwiftifyMacros.h
//  MacrosExamples
//
//  Created by Danila Gusev on 3/29/18.
//  Copyright © 2018 josshad. All rights reserved.
//

#ifndef SwiftifyMacros_h
#define SwiftifyMacros_h

#define SwiftyUNUSEDMARK_(a) __unused var_##a
#define SwiftyUNUSEDMARK(a) SwiftyUNUSEDMARK_(a)

#define _ SwiftyUNUSEDMARK(__COUNTER__)

#ifndef var
#   define var __auto_type
#endif

#ifndef let
#   define let __auto_type const
#endif

#define CLAMP(value, min, max) MIN(max, MAX(min, value))

#define force_unwrap(obj) ({ \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Wlanguage-extension-token\"") \
        _Pragma("clang diagnostic ignored \"-Wauto-var-id\"") \
        let _o = ((typeof(obj))(obj)); \
        _Pragma("clang diagnostic pop") \
        NSCAssert(_o, @"Force unwrap nil value"); \
        _o; \
})

#define self_cast(obj) ({ \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Wlanguage-extension-token\"") \
        let _o = ((typeof(self))(obj)); \
        _Pragma("clang diagnostic pop") \
        _o; \
})

#define NS_MainThreadAssert(desc, ...) NSAssert([NSThread isMainThread], desc, ##__VA_ARGS__)
#define NSMainThreadAssert() NS_MainThreadAssert(@"Must be called from main thread only!")

#endif /* SwiftifyMacros_h */
