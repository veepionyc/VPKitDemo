Pod::Spec.new do |s|

s.name              = "VPKit"
s.version = "2.4.26"
s.summary			= "VPKit vends veeps."
s.homepage          = "http://www.veepio.com"

s.author            = { 'veepio' => 'sdk_support@veepio.com' }
s.license           = { :type => 'MIT', :file => 'LICENSE' }

s.platform          = :ios
s.source            = { :git => "https://github.com/veepionyc/VPKitDemo.git",:tag => "#{s.version}"}

s.ios.deployment_target = '9.0'
s.ios.vendored_frameworks = 'VPKit.framework'	
    
end
