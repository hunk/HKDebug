//
//  HKDebug.m
//  HKDebug
//
//  Created by hunk on 2/9/16.
//  Copyright © 2016 hunk. All rights reserved.
//

#import "HKDebug.h"

void hunkCustomLog(NSString *format, ...) {
    
    va_list argumentList;
    va_start(argumentList, format);
    NSMutableString * message = [[NSMutableString alloc] initWithFormat:format
                                                              arguments:argumentList];
//    [message replaceOccurrencesOfString:@"::" withString:@":" options:0 range:NSMakeRange(0, [message length])];
//    NSLogv(message, argumentList);
    va_end(argumentList);
    
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@"yyyy-MM-dd HH:mm:ss.SSS"];
    NSString *strToday = [dateFormat  stringFromDate:[NSDate date]];
    printf("%s\n", [[NSString stringWithFormat:@"%@ %@",strToday,message] UTF8String]);
}
