#
# Be sure to run `pod lib lint DMengAdSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'DMengAdSDK'
  s.version          = '0.1.0'
  s.summary          = '多盟广告SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/dmdsp/DMengAdSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shilin.liu' => 'shilin.liu@domob.cn' }
  s.source           = { :git => 'https://github.com/dmdsp/DMengAdSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.pod_target_xcconfig = {
         'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
     }
#  s.source_files = 'DMengAdSDK/Classes/**/*'
  
  s.frameworks = 'AdSupport', 'AppTrackingTransparency', 'CoreLocation', 'CoreMotion', 'CoreTelephony'
  s.dependency 'AFNetworking'
  s.dependency 'Protobuf', '~> 3.20.0'
  s.dependency 'Masonry', '1.1.0'                  
  s.dependency 'SDWebImage'

  s.static_framework = true
  s.vendored_frameworks = 'DMengAdSDK/Classes/DMAdSDK.xcframework'
  
  s.resource_bundles = {
      'DMAdSDK_Bundle' => ['DMengAdSDK/Classes/DMAdSDK_Bundle.bundle']
  }
  
end
