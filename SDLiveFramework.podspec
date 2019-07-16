#
# Be sure to run `pod lib lint SDLiveProject.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'SDLiveFramework'
  s.version          = '1.0.1'
  s.summary          = 'A short description of SDLiveProject.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/jokerYellow/SDLiveProject'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'jokerYellow' => 'huangyaqing@021.com' }
  s.source           = { :git => 'http://172.16.117.224/iosenterprise/SDLiveProject.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  s.dependency 'SocketRocket'
  s.dependency 'YYModel'
  s.dependency 'SDWebImage'
  s.source_files = 'README.md', 'ChangeLog.md'
  s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  s.exclude_files = 'docs/**/*' 
  s.libraries = 'stdc++', 'z', 'bz2' 
  s.frameworks =  'AudioToolbox', 'UIKit', 'CoreGraphics', 'AVFoundation', 'CoreMedia', 'CoreVideo', 'MediaPlayer', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'VideoToolbox', 'SystemConfiguration'
  s.vendored_frameworks = 'SDLiveProject.framework'
end
