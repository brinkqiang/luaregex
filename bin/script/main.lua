-- lua script

local luaregex = require("luaregex")

local reg = luaregex.luaregex.new()

local ret = reg:match("subject subject2", "(sub)(.*)")

for i, v in ipairs(ret) do
    print(i, v)
end 