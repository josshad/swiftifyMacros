//
//  AppDelegate.m
//  MacrosExamples
//
//  Created by Danila Gusev on 3/29/18.
//  Copyright © 2018 josshad. All rights reserved.
//

#import "AppDelegate.h"
#import "SwiftifyMacros.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

// `_` instead of __unused
- (BOOL)application:(UIApplication *)_ didFinishLaunchingWithOptions:(NSDictionary *)_ {
    
    // Auto types
    let a = 10;
    var b = 5;
    b += a;
    NSLog(@"%d", b);
    
    // `_` instead of __unused
    [UIView animateWithDuration:0 animations:^{
        // Some code
    } completion:^(BOOL _) {
        // Some code
    }];
    
    //Clamp
    b += arc4random()%100;
    b = CLAMP(b, 10, 90); // b in [10, 90]
    
    NSLog(@"%d", b);
    
    
    // Force unwrap
    NSString * _Nullable maybeS = arc4random()%2?@"Dummy":nil;
    if (maybeS) {
        [self foo:force_unwrap(maybeS)];
    }
    return YES;
}

- (void)foo:(NSString * _Nonnull)string {
    NSParameterAssert(string);
    NSLog(@"%@",string);
}

@end
