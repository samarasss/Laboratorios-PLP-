divisores :: Int -> [Int]
divisores n = [ x | x <- [1 .. n], ((mod n x) == 0)]

verifica :: Int -> Bool
verifica n = if (divisores n) == [1,n] then True else False

primoCasado :: Int -> String
primoCasado n
	| verifica(nSoma) && verifica(n) = "PRIMO CASADO!"
	| verifica(n) = "PRIMO!"
	| otherwise = "NAO PRIMO!"
	where nSoma = n + 2


main = do
	n <- getLine
	let resultado = primoCasado (read n)
	print resultado
