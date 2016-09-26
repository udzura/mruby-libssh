# mruby-libssh   [![Build Status](https://travis-ci.org/udzura/mruby-libssh.svg?branch=master)](https://travis-ci.org/udzura/mruby-libssh)
LibSSH class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/mruby-libssh'
end
```
## example
```ruby
p LibSSH.hi
#=> "hi!!"
t = LibSSH.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the LGPL-2.1 License:
- see LICENSE file
