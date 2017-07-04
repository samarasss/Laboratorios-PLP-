numeroPerfeito :: Int -> [Int]
numeroPerfeito num = [ x | x <- [1 .. num-1], ((mod num x) == 0)]

verifica_eh_perfeito :: Int -> Bool
verifica_eh_perfeito num
		| ((sum (numeroPerfeito num)) == num) = True
		| otherwise = False





main = do

	x <- getLine

	let resultado = verifica_eh_perfeito (read x)
	print resultado
