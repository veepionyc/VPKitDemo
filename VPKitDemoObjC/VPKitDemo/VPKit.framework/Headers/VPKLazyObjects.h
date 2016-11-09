//
//  FNLazyLayout.h
//  FNAutoLayout
//
//  Created by jonathan on 19/08/2015.
//  Copyright (c) 2015 foundry. All rights reserved.
//

#ifndef FNAutoLayout_VPKLazyLayout_h
#define FNAutoLayout_VPKLazyLayout_h


#define vpk_lazyObject(class,name)                                          \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
}                                                                       \
return _##name;                                                         \
}                                                                       \

#define vpk_lazyView(class,name)                                            \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
}                                                                       \
return _##name;                                                         \
}                                                                       \

#define vpk_lazyViewWithAutolayout(class,name)                              \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
_##name.translatesAutoresizingMaskIntoConstraints = NO;                 \
}                                                                       \
return _##name;                                                         \
}                                                                       \



#define vpk_lazyAddView(class,name)                                         \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
if ([self respondsToSelector:@selector(contentView)]) {                 \
[[(id)self contentView] addSubview:_##name];                            \
} else if ([self respondsToSelector:@selector(addSubview:)]) {          \
[(id)self addSubview:_##name];                                          \
} else {                                                                \
[[(id)self view] addSubview:_##name];                                   \
}                                                                       \
}                                                                       \
return _##name;                                                         \
}                                                                       \



#define vpk_lazyAddViewWithAutolayout(class,name)                           \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
_##name.translatesAutoresizingMaskIntoConstraints = NO;                 \
if ([self respondsToSelector:@selector(contentView)]) {                 \
[[(id)self contentView] vpk_addView:_##name withName:@#name];               \
} else if ([self respondsToSelector:@selector(addSubview:)]) {          \
[(id)self vpk_addView:_##name withName:@#name];                             \
} else {                                                                \
[[(id)self view] vpk_addView:_##name withName:@#name];                      \
}                                                                       \
}                                                                       \
return _##name;                                                         \
}                                                                       \


#define vpk_lazyAddViewToViewController(class,name)                         \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
[self.view addSubview:_##name];                                         \
}                                                                       \
return _##name;                                                         \
}                                                                       \

#define vpk_lazyAddViewToViewControllerWithAutolayout(class,name)           \
- (class*)name {                                                        \
if (!_##name) {                                                         \
_##name = [[class alloc] init];                                         \
_##name.translatesAutoresizingMaskIntoConstraints = NO;                 \
[self.view vpk_addView:_##name withName:@#name];                            \
}                                                                       \
return _##name;                                                         \
}                                                                       \


#define vpk_addViewWithAutolayout(subview)                                  \
subview.translatesAutoresizingMaskIntoConstraints = NO;                 \
if ([self respondsToSelector:@selector(contentView)]) {                 \
[[(id)self contentView] vpk_addView:subview withName:@#subview];            \
} else if ([self respondsToSelector:@selector(addSubview:)]) {          \
[(id)self vpk_addView:subview withName:@#subview];                          \
} else {                                                                \
[[(id)self view] vpk_addView:subview withName:@#subview];                   \
}                                                                       \

#define vpk_addViewToViewWithAutolayout(view,subview)                       \
subview.translatesAutoresizingMaskIntoConstraints = NO;                 \
if ([view respondsToSelector:@selector(contentView)]) {                 \
[[(id)view contentView] vpk_addView:subview withName:@#subview];            \
} else if ([view respondsToSelector:@selector(addSubview:)]) {          \
[(id)view vpk_addView:subview withName:@#subview];                          \
}                                                                      \


#endif
