##
## LibSSH Test
##

assert("LibSSH#hello") do
  t = LibSSH.new "hello"
  assert_equal("hello", t.hello)
end

assert("LibSSH#bye") do
  t = LibSSH.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("LibSSH.hi") do
  assert_equal("hi!!", LibSSH.hi)
end
