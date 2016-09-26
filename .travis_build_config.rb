MRuby::Build.new do |conf|
  toolchain :clang
  conf.gembox 'default'
  conf.gem '../mruby-libssh'
  conf.enable_test
end
