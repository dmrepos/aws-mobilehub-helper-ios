source "https://github.com/CocoaPods/Specs.git"

ENV['SWIFT_VERSION'] = '5'
platform :ios, "12.0"

target "AWSMobileHubHelper" do
  pod "AWSSNS", "2.19.1"
  pod "AWSS3", "2.19.1"
  pod "AWSLambda", "2.19.1"
  pod "AWSCore", "2.19.1"

  post_install do |installer|
    installer.pods_project.build_configurations.each do |config|
      if config.name == "Release"
        config.build_settings["SWIFT_COMPILATION_MODE"] = "wholemodule"
        config.build_settings["SWIFT_OPTIMIZATION_LEVEL"] = "-Osize"
      else
        config.build_settings["SWIFT_COMPILATION_MODE"] = "singlefile"
        config.build_settings["SWIFT_OPTIMIZATION_LEVEL"] = "-Onone"
      end
    end
    installer.pods_project.targets.each do |target|
      target.build_configurations.each do |config|
        config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '12.0'
      end
    end
  end
end
