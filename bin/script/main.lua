-- lua script

local luaregex = require("luaregex")

local reg = luaregex.luaregex.new()

local ret = reg:match("hello htylo htyto htylt", "(h\\w+lo)")

for i, v in ipairs(ret) do
    print(i, v)
end

local ret2 = reg:search("hello htylo htyto htylt", "(h\\w+lo)")

for i, v in ipairs(ret2) do
    print(i, v)
end