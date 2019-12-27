//
//  ViewController_Layout.m
//  VPKitDemo
//
//  Created by jonathan on 30/01/2018.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import "ViewController_AutoLayout.h"
#import <VPKit/VPKit.h>

@implementation ViewController (AutoLayout)

- (void)configureConstraints {
    for (UIView* view in self.view.subviews) {
        view.translatesAutoresizingMaskIntoConstraints = NO;
    };
    
    for (UIView* view in @[self.titleLabel,self.consumeLabel,self.createLabel,self.versionLabel]) {
        [view.leftAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.leftAnchor constant:20].active = YES;
        [view.rightAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.rightAnchor constant:-20].active = YES;
        [view.heightAnchor constraintEqualToConstant:30].active = YES;
    }
    
    NSMutableArray<UILayoutGuide*>* guides = [[NSMutableArray alloc] init];
    for (int i = 0; i<4; i++) {
        guides[i] = [[UILayoutGuide alloc] init];
        [self.view addLayoutGuide:guides[i]];
        if (i>0) {
            [guides[0].heightAnchor constraintEqualToAnchor:guides[i].heightAnchor].active = YES;
        }
    }

    [guides[0].topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor].active = YES;
    [guides[0].bottomAnchor constraintEqualToAnchor:self.titleLabel.topAnchor].active = YES;
    [self.titleLabel.bottomAnchor constraintEqualToAnchor:guides[1].topAnchor].active = YES;
    [guides[1].bottomAnchor constraintEqualToAnchor:self.viewerPreview1.topAnchor].active = YES;
    [self.viewerPreview1.bottomAnchor constraintEqualToAnchor:self.consumeLabel.topAnchor].active = YES;
    [self.consumeLabel.bottomAnchor constraintEqualToAnchor:guides[2].topAnchor].active = YES;
    [guides[2].bottomAnchor constraintEqualToAnchor:self.viewerPreview2.topAnchor].active = YES;
    [self.viewerPreview2.bottomAnchor constraintEqualToAnchor:self.createLabel.topAnchor].active = YES;
    [self.createLabel.bottomAnchor constraintEqualToAnchor:guides[3].topAnchor].active = YES;
    [guides[3].bottomAnchor constraintEqualToAnchor:self.versionLabel.topAnchor].active = YES;
    
    [self.versionLabel.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor].active = YES;
    
    [self.viewerPreview1.heightAnchor constraintEqualToAnchor:self.view.heightAnchor multiplier:0.28].active = YES;
    [self.viewerPreview2.heightAnchor constraintEqualToAnchor:self.view.heightAnchor multiplier:0.28].active = YES;;
    [self.viewerPreview1.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor].active =YES;
    [self.viewerPreview2.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor].active =YES;
    
}

- (void)updateViewConstraints {
    [super updateViewConstraints];
    for (NSLayoutConstraint* constraint in self.constraints) {
        [self.view removeConstraint:constraint];
    }
    for (UIImageView* view in @[self.viewerPreview1,self.viewerPreview2]) {
        CGSize size = view.image.size;
        if (size.height > 0) {
            [self.constraints addObject:[self alignWidthToHeight:view ratio:size.width/size.height]];
        }
    }
    [self.view addConstraints:self.constraints];
    
}


- (NSLayoutConstraint*)alignWidthToHeight:(UIView*)view ratio:(CGFloat)ratio{
    return
    [NSLayoutConstraint constraintWithItem:view
                                 attribute:NSLayoutAttributeWidth
                                 relatedBy:NSLayoutRelationEqual
                                    toItem:view
                                 attribute:NSLayoutAttributeHeight
                                multiplier:ratio
                                  constant:0];
}

- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection {
    [super traitCollectionDidChange:previousTraitCollection];
    [self updateViewConstraints];
    
}


@end
