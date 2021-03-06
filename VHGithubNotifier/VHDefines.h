//
//  VHDefines.h
//  VHGithubNotifier
//
//  Created by viktorhuang on 2016/12/25.
//  Copyright © 2016年 黄伟平. All rights reserved.
//

#ifndef VHDefines_h
#define VHDefines_h

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import "VHGithubNotifierEnums.h"
#import "VHLog.h"

const static CGFloat TAB_VC_ARROW_WIDTH = 14;
const static CGFloat TAB_VC_ARROW_HEIGHT = 7;
const static CGFloat TAB_VC_TITLE_HEIGHT = 40;
const static CGFloat TAB_VC_CORNER_RADIUS = 8;

#define RELEASE (DEBUG == NO)

#define RELEASE_CODE(code) if (RELEASE) {code;}

#define DEBUG_CODE(code) if (DEBUG) {code;}

#define RGB(R,G,B) [NSColor colorWithRed:R/255.0f green:G/255.0f blue:B/255.0f alpha:1.0f]

#define RGBA(R,G,B,A) [NSColor colorWithRed:R/255.0f green:G/255.0f blue:B/255.0f alpha:A]

#define STATUS_ITEM_PRESSED_LIGHT RGB(45, 102, 239)

#define STATUS_ITEM_PRESSED_DARK RGB(45, 102, 239)

#define PRIMARY_COLOR RGB(3, 169, 244)  // #03A9F4  

#define AVOID_NIL_STRING(x) ((x) ? (x) : @"")

#define AVOID_NIL_ATTRIBUTE_STRING(x) ((x) ? (x) : [[NSMutableAttributedString alloc] initWithString:@""])

#define AVOID_NAN(x) (x = isnan(x) ? (0) : x)

#define IF_NIL_STRING_THEN_TIP(x) ((x) ? (x) : (@""))

#define IF_NIL_ATTRIBUTE_STRING_THEN_TIP(x) ((x) ? (x) : [[NSMutableAttributedString alloc] initWithString:@""])

#define BROWSE_STRING(name) [NSString stringWithFormat:@"Click to visit %@ in browser.", name]

#define SAFE_CAST(obj, className) ([(obj) isKindOfClass:[(className) class]] ? (obj) : (nil))

#define IN_MAIN_THREAD(code) dispatch_async(dispatch_get_main_queue(), ^{code;})

#define MUST_IN_MAIN_THREAD NSAssert([NSThread isMainThread], @"This methods should be called in main thread!");

#define NOTIFICATION_POST(name) [[NSNotificationCenter defaultCenter] postNotificationName:name object:nil userInfo:nil]

#define NOTIFICATION_POST_IN_MAIN_THREAD(name) IN_MAIN_THREAD(NOTIFICATION_POST(name))

#define NOTIFICATION_POST_WITH_OBJECT(name, object2) [[NSNotificationCenter defaultCenter] postNotificationName:name object:object2 userInfo:nil]

#define GLOBAL_QUEUE dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

#define DELAY_EXECUTE_IN_MAIN(seconds, code) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, seconds * NSEC_PER_SEC), dispatch_get_main_queue(), ^{ \
code; \
}); \

#define QM_STRING_CONCAT(A, B) QM_STRING_CONCAT_(A, B)

#define QM_STRING_CONCAT_(A, B) A ## B

#define WEAK_SELF(VAR) \
__weak __typeof__(VAR) QM_STRING_CONCAT(VAR, _weak_) = (VAR)

#define STRONG_SELF(VAR) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
__strong __typeof__(VAR) VAR = QM_STRING_CONCAT(VAR, _weak_) \
_Pragma("clang diagnostic pop")

#endif /* VHDefines_h */
