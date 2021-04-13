#
#  Be sure to run `pod s lint NewFinal.pods' to ensure this is a
#  valid s and to remove all comments including this before submitting the s.
#
#  To learn more about Pods attributes see https://guides.cocoapods.org/syntax/pods.html
#  To see working Podss in the CocoaPods repo see https://github.com/CocoaPods/ss/
#

Pod::Spec.new do |s|

  # ―――  s Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "NewFinal"
  s.version      = "0.0.1"
  s.summary      = "A short description of NewFinal."

  s.description  = <<-DESC
  This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
                   DESC

  s.homepage     = "https://github.com/marmelroy/Zip"

  s.license      = "MIT"

  s.author             = { "TrungCrit" => "Trung10101995@gmail.com" }

  s.source       = { :git => "https://github.com/marmelroy/Zip.git", :tag => "#{s.version}" }

  s.source_files = 'NewFinal/*.{swift,h}',
  s.public_header_files = 'NewFinal/*.h'
  s.pod_target_xcconfig = {'SWIFT_INCLUDE_PATHS' => '$(SRCROOT)/NewFinal/NewFinal/**','LIBRARY_SEARCH_PATHS' => '$(SRCROOT)/NewFinal/NewFinal/'}
  s.libraries = 'z'
  s.preserve_paths  = 'NewFinal/module/module.modulemap'

end
