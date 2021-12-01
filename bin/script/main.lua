-- lua script

local luaregex = require("luaregex")

local reg = luaregex.luaregex.new()

local ret = reg:match("hello", "(h\\w+lo)")

for i, v in ipairs(ret) do
    print("match", i, v)
end

local ret2 = reg:search("hello htylo htyto htylt", "(h\\w+lo)")

for i, v in ipairs(ret2) do
    print("search", i, v)
end