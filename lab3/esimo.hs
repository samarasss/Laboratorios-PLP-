i_esimo :: Int -> [Int] -> Int
i_esimo index list = list !! (index-1)
 
 
main = do
	list <- getLine
	index <- getLine
	let resultado = i_esimo (read index) (read list)
	print resultado
