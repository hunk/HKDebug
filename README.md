[![CI Status](http://img.shields.io/travis/hunk/SlideMenu3D.svg?style=flat)](https://travis-ci.org/hunk/HKDebug)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)](https://raw.githubusercontent.com/hunk/HKDebug/master/LICENSE)
[![Platform](https://img.shields.io/cocoapods/p/SlideMenu3D.svg?style=flat)](https://github.com/hunk/HKDebug)
[![Language Objective-c](https://img.shields.io/badge/Language-Objective%20C-yellow.svg)](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html)

# HKDebug
Another custom debug log with colors (based in [SwiftyBeaver](https://github.com/SwiftyBeaver/SwiftyBeaver) but for Objective-C) with help of [XcodeColors](https://github.com/robbiehanson/XcodeColors)

I love [SwiftyBeaver](https://github.com/SwiftyBeaver/SwiftyBeaver), it is a realy good. but i have some projects in Objective-C and i want the same output for the Xcode console. [SwiftyBeaver](https://github.com/SwiftyBeaver/SwiftyBeaver) have a wrapper [SBObjectiveCWrapper](https://github.com/SwiftyBeaver/SBObjectiveCWrapper) for Objective-C but you need a AppDelegate in Swift and my old proyects are all in Objective-C. then i need change my AppDelegate to swfit version, add SwiftyBeaver and SBObjectiveCWrapper, set the options for SwiftyBeaver.

So, i decided to make this little class (functions and macros) for have the same output.

<img src="https://raw.githubusercontent.com/hunk/MediaDemo/master/HKDebug/console.png">

##Installation

###CocoaPods
ToDo: add CocoaPods file

###Download
1. Download the [Repository](https://github.com/hunk/HKDebug/archive/master.zip)
2. Drag & drop the `HKDebug.[h|m]` files from `/Classes` into your project (make sure "Copy items if needed" is checked)

###Usage

Add `#import "HKDebug.h"` in your files where you need or if you use `.pch` add here and uses in all your files.

Now you can use the follow functions: 

```objective-c
    // Debug log \o/
    HKNormal(@"normal log without color, but whit the format of HK");
    HKVerbose(@"normal log with Verbose in gray");
    HKDebug(@"this line is with a debug word in %@",@"blue");
    HKInfo(@"a info log");
    HKWarning(@"oh, no, oh no, this is not happening");
    HKError(@"aahhhhh, help!!!!!!");
    HKAlt(@"alternative color");
    HKOpt(@"optional color");
    
    //All lines is in color
    HKFullColor(true);
    HKVerbose(@"this is a integer %zd",123);
    HKInfo(@"and this is a float %f",-123.45678);
    HKWarning(@"a date:%@",[NSDate date]);
    HKError(@"array %@",@[@"item 1", @"item 2", @"item 3"]);
    HKAlt(@"dictionary %@",@{@"name": @"Edgar G", @"nick": @"@hunk"});
```


###Options
You can choosen the elements for the output. this simples macros enable o disable some elements of the log.

```objective-c
HKFullColor(true); // all the line is in color, default value is false
HKShowDate(false); // show/hide datetime in the log, default value is true
HKShowFile(false); // show/hide name of file in the log, default value is true
HKShowFunc(false); // show/hide name of function in the log, default value is true
HKShowLine(false); // show/hide line number in the log, default value is true

```

###ToDo

output in a file


###Don't show colors?
Check if you have installed [XcodeColors](https://github.com/robbiehanson/XcodeColors)

-  Testing to see if XcodeColors is installed and enabled:

	```objective-c
	char *xcode_colors = getenv("XcodeColors");
	if (xcode_colors && (strcmp(xcode_colors, "YES") == 0))
	{
   	// XcodeColors is installed and enabled!
	}
	```


##License

HKDebug is released under the [MIT License](https://github.com/hunk/HKDebug/blob/master/LICENSE).
