//
//  HKDebug.m
//  HKDebug
//
//  Created by hunk on 2/9/16.
//  Copyright © 2016 hunk. All rights reserved.
//

#import "HKDebug.h"

@interface HKLog() {
    BOOL fullColor;
    BOOL showDate;
    BOOL showFile;
    BOOL showFunction;
    BOOL showLine;
}
@end

@implementation HKLog

+ (instancetype)sharedInstance {
    static id sharedInstance = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    
    return sharedInstance;
}

- (instancetype)init {
    if ((self = [super init])) {
        fullColor = false;
        showDate = true;
        showFile = true;
        showFunction = true;
        showLine = true;
    }
    
    return self;
}

+ (void)fullColor:(BOOL)value {
    [[self sharedInstance] fullColor:value];
}

- (void)fullColor:(BOOL)value {
    fullColor = value;
}

+ (void)showDate:(BOOL)value {
    [[self sharedInstance] showDate:value];
}

- (void)showDate:(BOOL)value {
    showDate = value;
}

+ (void)showFile:(BOOL)value {
    [[self sharedInstance] showFile:value];
}

- (void)showFile:(BOOL)value {
    showFile = value;
}

+ (void)showFunction:(BOOL)value {
    [[self sharedInstance] showFunction:value];
}

- (void)showFunction:(BOOL)value{
    showFunction = value;
}

+ (void)showLine:(BOOL)value{
    [[self sharedInstance] showLine:value];
}

- (void)showLine:(BOOL)value{
    showFile = value;
}

+ (void)log:(HKTypeOfDebug)type file:(const char *)file function:(const char *)function line:(NSUInteger)line format:(NSString *)format, ... {
    
    va_list argumentList;
    if (format) {
        va_start(argumentList, format);
        NSString *message = [[NSString alloc] initWithFormat:format arguments:argumentList];
        [[self sharedInstance] messageLog:type
                                     file:[NSString stringWithFormat:@"%s",file]
                                 function:[NSString stringWithFormat:@"%s",function]
                                     line:line
                                  message:message];
        va_end(argumentList);
    }
}

- (void)log:(HKTypeOfDebug)type file:(const char *)file function:(const char *)function line:(NSUInteger)line format:(NSString *)format, ... {
   
    va_list argumentList;
    if (format) {
        va_start(argumentList, format);
        NSString *message = [[NSString alloc] initWithFormat:format arguments:argumentList];
        [self messageLog:type
                    file:[NSString stringWithFormat:@"%s",file]
                function:[NSString stringWithFormat:@"%s",function]
                    line:line
                 message:message];
        va_end(argumentList);
    }
}

- (void)messageLog:(HKTypeOfDebug)type file:(NSString*)file function:(NSString*)function line:(NSUInteger)line message:(NSString *)message {
    
    NSString *preLog = @"";
    NSString *logMessage = @"";
    NSString *postLog = @"";
    HKColorAndText strType = [self strTypeDebug:type];
    
    if (fullColor) {
        preLog = [preLog stringByAppendingFormat:@"%@%@",HKDEBUG_ESCAPE,strType.HKColorStr];
    }
    
    //Date
    if (showDate) {
        NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
        [dateFormat setDateFormat:@"yyyy-MM-dd HH:mm:ss.SSS"];
        NSString *dateNow = [dateFormat  stringFromDate:[NSDate date]];
        logMessage = [logMessage stringByAppendingFormat:@"%@ ",dateNow];
    }
    
    //File
    if (showFile) {
        NSString *fileName = [file lastPathComponent];
        if ([fileName rangeOfString:@"." options:NSBackwardsSearch].location != NSNotFound) {
            NSArray *parts = [fileName componentsSeparatedByString:@"."];
            fileName = [parts firstObject];
        }
        if ( ![logMessage hasSuffix:@" "] && logMessage.length > 0) {
            logMessage = [logMessage stringByAppendingFormat:@" "];
        }
        logMessage = [logMessage stringByAppendingFormat:@"%@",fileName];
    }
    
    //Function
    if (showFunction) {
        NSInteger whiteSpaceLocation = [function rangeOfString:@"\\s" options:NSRegularExpressionSearch].location;
        if (whiteSpaceLocation != NSNotFound) {
            function = [function substringFromIndex:whiteSpaceLocation+1];
        }
        if ( [function hasSuffix:@"]"] ) {
            function = [function stringByReplacingCharactersInRange:NSMakeRange(function.length -1, 1) withString:@""];
        }
        
        if ( ![logMessage hasSuffix:@" "] && showFile ) {
            logMessage = [logMessage stringByAppendingFormat:@"."];
        }
        logMessage = [logMessage stringByAppendingFormat:@"%@",function];
    }

    //Line
    if (showLine) {
        NSString *strLine = [NSString stringWithFormat:@":%zd",line];
        if ( [logMessage hasSuffix:@":"] && showLine ) {
            strLine = [NSString stringWithFormat:@"%zd",line];
        }
        if (!showFunction && !showFile) {
            strLine = [NSString stringWithFormat:@"L:%zd",line];
        }
        logMessage = [logMessage stringByAppendingFormat:@"%@",strLine];
    }

    //Type
    if (strType.HKTextStr.length != 0 && !fullColor ) {
        if ( ![logMessage hasSuffix:@" "] && logMessage.length > 0) {
            logMessage = [logMessage stringByAppendingFormat:@" "];
        }
        logMessage = [logMessage stringByAppendingFormat:@"%@%@%@%@:",HKDEBUG_ESCAPE,strType.HKColorStr,strType.HKTextStr,HKDEBUG_RESET];
    }

    //Message
    if ( ![logMessage hasSuffix:@" "] && logMessage.length > 0 ) {
        logMessage = [logMessage stringByAppendingFormat:@" "];
    }
    
    if (fullColor) {
        postLog = [postLog stringByAppendingFormat:@"%@",HKDEBUG_RESET];
    }
    
    logMessage = [NSString stringWithFormat:@"%@%@%@%@",preLog,logMessage,message,postLog];
    
    printf("%s\n", [logMessage UTF8String]);    
}

-(HKColorAndText)strTypeDebug:(HKTypeOfDebug)type {
    
    HKColorAndText infoColorAndText;
    switch(type) {
        case HKTypeNormal:
            infoColorAndText.HKTextStr = @"";
            infoColorAndText.HKColorStr = @""; //without color
            break;
        case HKTypeVerbose:
            infoColorAndText.HKTextStr = @"VERBOSE";
            infoColorAndText.HKColorStr = @"fg200,200,200;"; //Silver
            break;
        case HKTypeDebug:
            infoColorAndText.HKTextStr = @"DEBUG";
            infoColorAndText.HKColorStr = @"fg0,0,255;"; //Blue
            break;
        case HKTypeInfo:
            infoColorAndText.HKTextStr = @"INFO";
            infoColorAndText.HKColorStr = @"fg0,255,0;"; //Green
            break;
        case HKTypeWarning:
            infoColorAndText.HKTextStr = @"WARNING";
            infoColorAndText.HKColorStr = @"fg255,255,0;"; //Yellow
            break;
        case HKTypeError:
            infoColorAndText.HKTextStr = @"ERROR";
            infoColorAndText.HKColorStr = @"fg255,0,0;"; //Red
            break;
        case HKTypeAlternative:
            infoColorAndText.HKTextStr = @"ALTERNATIVE";
            infoColorAndText.HKColorStr = @"fg214,57,30;"; // Orange
            break;
        case HKTypeOptional:
            infoColorAndText.HKTextStr = @"OPTIONAL";
            infoColorAndText.HKColorStr = @"fg0,255,255;"; //Cyan
            break;
        default:
            infoColorAndText.HKTextStr = @"";
            infoColorAndText.HKColorStr = @"fg200,200,200;";
    }
    return infoColorAndText;
}

@end