Pod::Spec.new do |s|

  s.name              = "VPKit"
  s.version           = "2.11.8"
  s.summary           = "VPKit vends veeps."
  s.description       = "VPKit turns images and video into interactive VEEP media: tracked hotspots that open linked web content inside the host app. Binary xcframework for devices and arm64/x86_64 simulators."
  s.homepage          = "https://veepionyc.github.io/"
  s.documentation_url = "https://veepionyc.github.io/reference/ios/2/11/8/"

  s.author            = { 'veepio' => 'sdk_support@veepio.com' }
  s.license           = { :type => 'Commercial', :file => 'LICENSE' }

  s.platform          = :ios, '12.0'
  s.source            = { :git => "https://github.com/veepionyc/VPKitDemo.git", :tag => "#{s.version}" }

  s.ios.deployment_target = '12.0'
  s.vendored_frameworks   = "VPKit.xcframework"

end
