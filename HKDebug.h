//
//  HKDebug.h
//  HKDebug
//
//  Created by hunk on 2/9/16.
//  Copyright © 2016 hunk. All rights reserved.
//

#import <Foundation/Foundation.h>

#define XCODE_COLORS_ESCAPE @"\033["
#define XCODE_COLORS_RESET_FG  XCODE_COLORS_ESCAPE @"fg;" // Clear any foreground color
#define XCODE_COLORS_RESET_BG  XCODE_COLORS_ESCAPE @"bg;" // Clear any background color
#define XCODE_COLORS_RESET     XCODE_COLORS_ESCAPE @";"

#define XCODE_COLORS_SILVER  @"fg200,200,200;"
#define XCODE_COLORS_BLUE    @"fg0,0,255;"
#define XCODE_COLORS_GREEN   @"fg0,255,0;"
#define XCODE_COLORS_YELLOW  @"fg255,255,0;"
#define XCODE_COLORS_RED     @"fg255,0,0;"
#define XCODE_COLORS_MAGENTA @"fg255,0,255;"
#define XCODE_COLORS_CYAN    @"fg0,255,255;"

#define XCODE_COLORS_VERBOSE @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_SILVER  @"VERBOSE"     XCODE_COLORS_RESET @": "
#define XCODE_COLORS_DEBUG   @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_BLUE    @"DEBUG"       XCODE_COLORS_RESET @": "
#define XCODE_COLORS_INFO    @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_GREEN   @"INFO"        XCODE_COLORS_RESET @": "
#define XCODE_COLORS_WARNING @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_YELLOW  @"WARNING"     XCODE_COLORS_RESET @": "
#define XCODE_COLORS_ERROR   @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_RED     @"ERROR"       XCODE_COLORS_RESET @": "
#define XCODE_COLORS_ALT     @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_MAGENTA @"ALTERNATIVE" XCODE_COLORS_RESET @": "
#define XCODE_COLORS_OPT     @"%@.%@:%d " XCODE_COLORS_ESCAPE XCODE_COLORS_CYAN    @"OPTIONAL"    XCODE_COLORS_RESET @": "
//#define XCODE_COLORS_MORE    @"%@:%d "

#define XCODE_FILENAME [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] componentsSeparatedByString:@"."] firstObject]

#ifdef DEBUG
#define HVerbose(frmt, ...) hunkCustomLog((XCODE_COLORS_VERBOSE frmt),[XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HDebug(frmt, ...)   hunkCustomLog((XCODE_COLORS_DEBUG frmt),  [XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HInfo(frmt, ...)    hunkCustomLog((XCODE_COLORS_INFO frmt),   [XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HWarning(frmt, ...) hunkCustomLog((XCODE_COLORS_WARNING frmt),[XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HError(frmt, ...)   hunkCustomLog((XCODE_COLORS_ERROR frmt),  [XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HAlt(frmt, ...)     hunkCustomLog((XCODE_COLORS_ALT frmt), [XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#define HOpt(frmt, ...)     hunkCustomLog((XCODE_COLORS_OPT frmt),[XCODE_FILENAME, NSStringFromSelector(_cmd), __LINE__, ##__VA_ARGS__)
#else
#define HVerbose
#define HDebug
#define HInfo
#define HWarning
#define HError
#define HAlt
#define HOpt
#endif

//#define NSLog(frmt, ...) hunkCustomLog((XCODE_MORE frmt),[[NSString stringWithUTF8String:__FILE__] lastPathComponent],__LINE__, ##__VA_ARGS__)

void hunkCustomLog(NSString *format, ...);