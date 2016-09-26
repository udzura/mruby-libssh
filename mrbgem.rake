MRuby::Gem::Specification.new('mruby-libssh') do |spec|
  spec.license = 'LGPL-2.1'
  spec.authors = 'Uchio Kondo'

  spec.cc.flags.concat `pkg-config --cflags libssh`.split
  spec.linker.flags << `pkg-config --libs libssh`.split.first
  spec.linker.libraries << 'ssh'
end
