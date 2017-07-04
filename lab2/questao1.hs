main = do

	a <- getLine
	b <- getLine
	c <- getLine
	d <- getLine
	
	let resultado = somador (read a) (read b) (read c) d

	print resultado

somador :: Bool -> Bool -> Bool -> String-> Bool
somador a b c d = if d == "OR" then (a || b || c)  else (a && b && c)




