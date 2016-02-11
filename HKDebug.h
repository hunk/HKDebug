//
//  HKDebug.h
//  HKDebug
//
//  Created by hunk on 2/9/16.
//  Copyright © 2016 hunk. All rights reserved.
//

#import <Foundation/Foundation.h>

#define HKDEBUG_ESCAPE          @"\033["
#define HKDEBUG_RESET_FG        HKDEBUG_ESCAPE @"fg;" // Clear any foreground color
#define HKDEBUG_RESET_BG HKDEBUG_ESCAPE @"bg;" // Clear any background color
#define HKDEBUG_RESET    HKDEBUG_ESCAPE @";"

#define HKDEBUG_SILVER  @"fg200,200,200;"
#define HKDEBUG_BLUE    @"fg0,0,255;"
#define HKDEBUG_GREEN   @"fg0,255,0;"
#define HKDEBUG_YELLOW  @"fg255,255,0;"
#define HKDEBUG_RED     @"fg255,0,0;"
#define HKDEBUG_MAGENTA @"fg255,0,255;"
#define HKDEBUG_CYAN    @"fg0,255,255;"

#define HKDEBUG_VERBOSE @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_SILVER  @"VERBOSE"     HKDEBUG_RESET @": "
#define HKDEBUG_DEBUG   @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_BLUE    @"DEBUG"       HKDEBUG_RESET @": "
#define HKDEBUG_INFO    @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_GREEN   @"INFO"        HKDEBUG_RESET @": "
#define HKDEBUG_WARNING @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_YELLOW  @"WARNING"     HKDEBUG_RESET @": "
#define HKDEBUG_ERROR   @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_RED     @"ERROR"       HKDEBUG_RESET @": "
#define HKDEBUG_ALT     @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_MAGENTA @"ALTERNATIVE" HKDEBUG_RESET @": "
#define HKDEBUG_OPT     @"%@.%@:%d " HKDEBUG_ESCAPE HKDEBUG_CYAN    @"OPTIONAL"    HKDEBUG_RESET @": "
//#define XCODE_COLORS_MORE    @"%@:%d "

#define HKDEBUG_FILENAME [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] componentsSeparatedByString:@"."] firstObject]

#ifdef DEBUG
#define HKVerbose(frmt, ...) hunkCustomLog( (HKDEBUG_VERBOSE frmt),[HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HKDebug(frmt, ...)   hunkCustomLog( (HKDEBUG_DEBUG frmt),  [HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HKInfo(frmt, ...)    hunkCustomLog( (HKDEBUG_INFO frmt),   [HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HKWarning(frmt, ...) hunkCustomLog( (HKDEBUG_WARNING frmt),[HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HKError(frmt, ...)   hunkCustomLog( (HKDEBUG_ERROR frmt),  [HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HKAlt(frmt, ...)     hunkCustomLog( (HKDEBUG_ALT frmt),    [HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HKOpt(frmt, ...)     hunkCustomLog( (HKDEBUG_OPT frmt),    [HKDEBUG_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#else
#define HKVerbose
#define HKDebug
#define HKInfo
#define HKWarning
#define HKError
#define HKAlt
#define HKOpt
#endif

//#define NSLog(frmt, ...) hunkCustomLog((XCODE_MORE frmt),[[NSString stringWithUTF8String:__FILE__] lastPathComponent],__LINE__, ##__VA_ARGS__)

void hunkCustomLog(NSString *format, ...);