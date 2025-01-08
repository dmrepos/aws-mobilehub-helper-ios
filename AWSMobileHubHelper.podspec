Pod::Spec.new do |spec|
  spec.name = "AWSMobileHubHelper"
  spec.version = "0.0.2"
  spec.platform = :ios, "12.0"
  spec.license = { :type => "Apache 2.0 License" }
  spec.homepage = "https://github.com/dmrepos/aws-mobilehub-helper-ios"
  spec.authors = { "Amazon" => "noreply@amazon.com" }
  spec.summary = "AWSMobileHubHelper"
  spec.source = { :git => "https://github.com/dmrepos/aws-mobilehub-helper-ios.git", :branch => "master", :tag => "v0.0.2" }
  spec.source_files = "AWSMobileHubHelper/**/*.{c,h,m,swift}"
  spec.resources = "AppAWSMobileHubHelperCore/**/*.{lproj,storyboard,xcdatamodeld,xib,xcassets,json}"
  spec.module_name = "AWSMobileHubHelper"
  spec.frameworks = "UIKit"
  spec.requires_arc = true
  spec.dependency "AWSSNS", "2.19.1"
  spec.dependency "AWSS3", "2.19.1"
  spec.dependency "AWSLambda", "2.19.1"
  spec.dependency "AWSCore", "2.19.1"
  spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(PODS_ROOT)/../../TS/**" }
  spec.xcconfig = { "FRAMEWORK_SEARCH_PATHS" => '"$(PODS_ROOT)/../.." "$(PODS_ROOT)/.." "$(SRCROOT)/.."' }
end
