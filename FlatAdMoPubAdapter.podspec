#
# Be sure to run `pod lib lint FlatAdMoPubAdapter.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'FlatAdMoPubAdapter'
  s.version          = '0.1.0'
  s.summary          = 'FlatAds_sdk MoPub Adapter'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
An FlatAds_sdk adapter 4 mopub.
                       DESC

  s.homepage         = 'https://github.com/flatads/FlatAdMoPubAdapter'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'flatads' => 'chenwh02@flatincbr.com' }
  s.source           = { :git => 'https://github.com/flatads/FlatAdMoPubAdapter.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.0'
  
  s.requires_arc = true
  s.static_framework = true

  s.source_files = 'FlatAdMoPubAdapter/Classes/**/*'
  
  # s.resource_bundles = {
  #   'FlatAdMoPubAdapter' => ['FlatAdMoPubAdapter/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'

  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES'
  }
  
  s.user_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES'
  }
  
  s.subspec 'Banner' do |sb|
    sb.source_files = "iOSMoPubAdapter/Banner/*.{h,m}"
  end
  
  s.subspec 'Configuration' do |sb|
    sb.source_files = "iOSMoPubAdapter/Configuration/*.{h,m}"
  end
  
  s.subspec 'Interstitial' do |sb|
    sb.source_files = "iOSMoPubAdapter/Interstitial/*.{h,m}"
  end
  
  s.subspec 'Native' do |sb|
    sb.source_files = "iOSMoPubAdapter/Native/*.{h,m}"
  end
  
  s.subspec 'Rewarded' do |sb|
    sb.source_files = "iOSMoPubAdapter/Rewarded/*.{h,m}"
  end

  s.subspec 'Util' do |sb|
    sb.source_files = "iOSMoPubAdapter/Util/*.{h,m}"
  end
  
  s.dependency "FlatAds_sdk", "~> 1.0.5"
  s.dependency "mopub-ios-sdk", "~> 5.17.0"
  
end