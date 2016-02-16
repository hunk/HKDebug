//
//  HKDebug.h
//  HKDebug
//
//  Created by hunk on 2/9/16.
//  Copyright © 2016 hunk. All rights reserved.
//

#import <Foundation/Foundation.h>

#define HKDEBUG_ESCAPE @"\033["
#define HKDEBUG_RESET HKDEBUG_ESCAPE @";"

#ifdef DEBUG
    #define HKNormal(frmt, ...)  [HKLog log:HKTypeNormal    file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKVerbose(frmt, ...) [HKLog log:HKTypeVerbose     file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKDebug(frmt, ...)   [HKLog log:HKTypeDebug       file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKInfo(frmt, ...)    [HKLog log:HKTypeInfo        file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKWarning(frmt, ...) [HKLog log:HKTypeWarning     file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKError(frmt, ...)   [HKLog log:HKTypeError       file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKAlt(frmt, ...)     [HKLog log:HKTypeAlternative file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKOpt(frmt, ...)     [HKLog log:HKTypeOptional    file:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:frmt,##__VA_ARGS__];
    #define HKFullColor(value)   [HKLog fullColor:value];
    #define HKShowDate(value)    [HKLog fullColor:value];
    #define HKShowFile(value)    [HKLog fullColor:value];
    #define HKShowFunc(value)    [HKLog fullColor:value];
    #define HKShowLine(value)    [HKLog fullColor:value];
#else
    #define HKNormal
    #define HKVerbose
    #define HKDebug
    #define HKInfo
    #define HKWarning
    #define HKError
    #define HKAlt
    #define HKOpt
    #define HKFullColor
    #define HKShowDate
    #define HKShowFile
    #define HKShowFunc
    #define HKShowLine
#endif

typedef enum {
    HKTypeNormal,
    HKTypeVerbose,
    HKTypeDebug,
    HKTypeInfo,
    HKTypeWarning,
    HKTypeError,
    HKTypeAlternative,
    HKTypeOptional
} HKTypeOfDebug;

typedef struct {
    __unsafe_unretained NSString *HKColorStr;
    __unsafe_unretained NSString *HKTextStr;
}HKColorAndText;

@interface HKLog : NSObject
+ (instancetype)sharedInstance;
+ (void)fullColor:(BOOL)value;
- (void)fullColor:(BOOL)value;
+ (void)showDate:(BOOL)value;
- (void)showDate:(BOOL)value;
+ (void)showFile:(BOOL)value;
- (void)showFile:(BOOL)value;
+ (void)showFunction:(BOOL)value;
- (void)showFunction:(BOOL)value;
+ (void)showLine:(BOOL)value;
- (void)showLine:(BOOL)value;
+ (void)log:(HKTypeOfDebug)type file:(const char *)file function:(const char *)function line:(NSUInteger)line format:(NSString *)format, ...;
- (void)log:(HKTypeOfDebug)type file:(const char *)file function:(const char *)function line:(NSUInteger)line format:(NSString *)format, ...;
- (void)messageLog:(HKTypeOfDebug)type file:(NSString*)file function:(NSString*)function line:(NSUInteger)line message:(NSString *)message;
@end


