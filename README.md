# HKDebug
Another custom Debug with Colors (based in [SwiftyBeaver](https://github.com/SwiftyBeaver/SwiftyBeaver) but for Objective-C) with help of [XcodeColors](https://github.com/robbiehanson/XcodeColors)

I love [SwiftyBeaver](https://github.com/SwiftyBeaver/SwiftyBeaver), it is a realy good. but i have some projects in Objective-C and i want the same output for the Xcode console. [SwiftyBeaver](https://github.com/SwiftyBeaver/SwiftyBeaver) have a wrapper [SBObjectiveCWrapper](https://github.com/SwiftyBeaver/SBObjectiveCWrapper) for Objective-C but you need a AppDelegate in Swift and my old proyects are all in Objective-C 

So, i decided to make this little class (function and macros) for have the same output.
<img src="https://raw.githubusercontent.com/hunk/MediaDemo/master/HKDebug/console.png">

##Installation

###Download
1. Download the [project](https://github.com/hunk/HKDebug/archive/master.zip)
2. Drag & drop the `HKDebug.[h|m]` files into your project (make sure "Copy items if needed" is checked)

###Usage

Add `#import "HKDebug.h"` in your files where you need or if you use `.pch` add here and uses in all your files.

Now you can use the follow functions: 

```objective-c
    HKVerbose("not so important");  // prio 1, VERBOSE in silver
    HKDebug("something to debug");  // prio 2, DEBUG in blue
    HKInfo("a nice information");   // prio 3, INFO in green
    HKWarning("oh no, that won’t be good");  // prio 4, WARNING in yellow
    HKError("ouch, an error did occur!"); // prio 5, ERROR in red
    HKAlt(@"alternative color"); // prio 5, ALTERNATIVE in magenta
    HKOpt(@"optional color"); // prio 5, OPTIONAL in cyan
    
    // log anything!
    HKVerbose(@"%zd",123);
    HKInfo(@"%zd",-123.45678);
    HKWarning(@"%@",[NSDate date]);
    HKError(@"%@",@[@"I", @"like", @"logs!"]);
    HKError(@"%@",@{@"name": @"Mr Bean", @"address": @"7 Some Street"});
```
### Don't show colors?
Check if you have installed [XcodeColors](https://github.com/robbiehanson/XcodeColors)

-  Testing to see if XcodeColors is installed and enabled:

	```objective-c
	char *xcode_colors = getenv("XcodeColors");
	if (xcode_colors && (strcmp(xcode_colors, "YES") == 0))
	{
   	// XcodeColors is installed and enabled!
	}
	```


## License

HKDebug is released under the [MIT License](https://github.com/hunk/HKDebug/blob/master/LICENSE).
