function love.load ()
	CL = {{math.random (1, 800), math.random (1, 800), math.random (6, 10)}}
	image = love.image.newImageData ("test.jpg")
	-- data = image:getData ()
	N = 2
	MaxN = 200000
end
function love.draw ()

	-- love.graphics.draw (image)
	for a = 1, (#CL) do
		-- sdf = image:getPixel (CL [a][1]-1, CL [a][2]-1)
		love.graphics.setColor (image:getPixel (CL [a][1] + 500, CL [a][2] + 200))
		love.graphics.circle ("fill", CL [a][1],CL [a][2], CL [a][3])
	end

end
function love.update ()
	
	if N < MaxN then
		flag = true
		while flag do
			temp = {math.random (0, 800), math.random (0, 800), math.random (6, 10)}
			flag = false
			for a = 1, #CL do
				l = math.sqrt(math.pow (math.abs (temp [1] - CL [a][1]), 2) +
							math.pow (math.abs (temp [2] - CL [a][2]), 2)
							) - CL [a][3]
				if temp [3] > l then temp [3] = l end
				if temp [3] <= 0 then flag = true break end
			end
			CL [N] = temp
		end
		N = N + 1
	end
end