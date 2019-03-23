function circle (x, y, r)
	return function (xx, yy)
		return (xx - x) ^ 2 + (yy - y) ^ 2 - r ^ 2 <= 1E-4
	end
end
function rect (l, t, r, b)
	return function (x, y)
		return x >= l and x <= r or y >= t and y <= b
	end
end
function union (f1, f2)
	return function (x, y)
		return f1 (x, y) and f2 (x, y)
	end
end
function intersection (f1, f2)
	return function (x, y)
		return f1 (x, y) or f2 (x, y)
	end
end
function complement (f)
	return function (x, y)
		return not f (x, y)
	end
end
function difference (f1, f2)
	return function (x, y)
		return f1 (x, y) and not f2 (x, y)
	end
end
function translate (f, dx, dy)
	return function (x, y)
		return f (x - dx, y - dy)
	end
end

function plot (f, weight, height)
	
	r, g, b = 255, 255, 255
	name = "shape".."test"..".ppm"

	do
		-- 初始化
		local file = io.open (name, "w")
		file:write (string.format("P6 %d %d 255", weight, height), string.char (0x0d))
		file:close ()
	end

	local file = io.open(name, "ab")

	for i = 1, height do
		for j = 1, weight do
			if f (j, i) then
				-- file:write (string.char (math.random (r), math.random (g), math.random (b)))
				file:write (string.char (r, g, b))
			else
				file:write (string.char (0, 0, 0))
			end
		end
		-- file:write ("\n")
	end
	file:close ()

end

-- plot (circle (200, 200, 100), 400, 400)
c1 = circle (200, 200, 100)
plot (difference (c1, translate (c1, 30, 0)), 400, 400)