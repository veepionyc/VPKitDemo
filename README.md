# VPKit

![](https://img.shields.io/badge/VPKit-2.11.8-blue.svg)
![](https://img.shields.io/cocoapods/v/VPKit.svg)
![](https://img.shields.io/cocoapods/p/VPKit.svg)
![](https://img.shields.io/badge/iOS-12.0%2B-lightgrey.svg)
![](https://img.shields.io/badge/obj--c-compatible-green.svg)
![](https://img.shields.io/badge/swift-compatible-green.svg)

This repository holds a binary distribution of the VPKit framework (version **2.11.8**) and demo host apps in Swift and Objective-C.

`VPKit.xcframework` is a dynamic xcframework with slices for `ios-arm64` (devices) and `ios-arm64_x86_64-simulator` (Apple silicon and Intel simulators). It is self-contained: no other frameworks need to be added alongside it.

## Requirements

- iOS 12.0 or later (the demo apps target iOS 15.0).
- Built and verified with Xcode 26.2.
- Apps built with the iOS 27 SDK must adopt the UIScene life cycle (`UIApplicationSceneManifest` in Info.plist and a `UIWindowSceneDelegate`). VPKit itself works under either life cycle; the demo apps show the minimal setup.
- VPKit ships a privacy manifest. It collects no advertising identifier unless the host app opts in with `sendIDFA(true)` and holds App Tracking Transparency authorisation. The demo apps do not opt in.

## Installation

### Swift Package Manager (recommended)

In Xcode choose *File > Add Package Dependencies…*, enter `https://github.com/veepionyc/VPKit-spm`, select version **2.11.8** and add one product to your app target: `VPKit-dynamic` or `VPKit-static`.

```swift
// Package.swift
.package(url: "https://github.com/veepionyc/VPKit-spm", exact: "2.11.8")
```

### CocoaPods

```ruby
platform :ios, '12.0'

target 'MyApp' do
  pod 'VPKit', '2.11.8'
end
```

Then run `pod install`.

### Manual

Use `VPKit.xcframework` from this repository, or download the dynamic or static zip from the [VPKit-spm 2.11.8 release](https://github.com/veepionyc/VPKit-spm/releases/tag/2.11.8). Drag it into your project and add it under *Frameworks, Libraries and Embedded Content*: **Embed & Sign** for the dynamic variant, **Do Not Embed** for the static one.

## Quick start

```swift
import VPKit

// application(_:didFinishLaunchingWithOptions:)
VPKit.setApplicationId(appId, clientId: clientId, clientSecret: clientSecret)
VPKit.environment().production = true

// in a view controller
preview.image = VPKImage(image: UIImage(named: "KrispyGlas")!, veepId: "1787")   // preview is a VPKPreview
```

Credentials come from the [Veepio developer portal](https://developer.veep.io). The demo apps contain test credentials for evaluation only.

## Demo apps

Each demo links `../VPKit.xcframework` directly; open the `.xcodeproj` and run.

| Folder | Language | Shows |
| --- | --- | --- |
| `demo_view_swift` | Swift | Quick-start integration: two `VPKPreview`s (image veep by URL and by veep id). |
| `demo_view_objc` | Objective-C | The same in Objective-C, plus a video veep and the pass-through tap delegate. |
| `demo_view_collectionview_swift` | Swift | `VPKPreview` in `UICollectionView` cells, veep'd and plain images, and handling rotation when the host app is portrait-only. |

Veep creation is not part of VPKit; it is provided by the separate VPKitMaker SDK (contact sdk_support@veepio.com).

## Documentation

- Guide: [veepionyc.github.io](https://veepionyc.github.io/)
- Class reference for 2.11.8: [veepionyc.github.io/reference/ios/2/11/8](https://veepionyc.github.io/reference/ios/2/11/8/)
- Help: sdk_support@veepio.com

![](https://veepionyc.github.io/assets/img/consume.jpg)

## Licence

VPKit is distributed in binary form under the terms in [LICENSE](LICENSE).
