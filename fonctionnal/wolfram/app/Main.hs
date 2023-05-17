{-
-- EPITECH PROJECT, 2023
-- wolframe
-- File description:
-- Main.hs
-}

import System.Exit (exitWith, ExitCode(..))
import System.Environment (getArgs)
import Data.Maybe (fromJust, fromMaybe, isJust, isNothing)
import Data.Bits (Bits(testBit))
import System.IO (hPutStrLn, stderr)
import Text.Read

data Options = Options {
    orule :: Maybe Int,
    ostart :: Int,
    olines :: Maybe Int,
    owin :: Int,
    omove :: Int
} deriving (Show)

data Glb = Glb {
    mid :: Int,
    width :: Int,
    height :: Int,
    rowLen :: Int
} deriving (Show)

data Pattern = Pattern {
    pat0 :: Bool,
    pat1 :: Bool,
    pat2 :: Bool,
    pat3 :: Bool,
    pat4 :: Bool,
    pat5 :: Bool,
    pat6 :: Bool,
    pat7 :: Bool
} deriving (Show)

data Save = Save {
    saved :: [[Bool]],
    index :: Int
} deriving (Show)

defaultOptions :: Options
defaultOptions = Options {
    orule = Nothing,
    ostart = 0,
    olines = Nothing,
    owin = 80,
    omove = 0
}

initSave :: [[Bool]] -> Glb -> Save
initSave grid glb = Save {
    saved = replicate (height glb) (replicate (rowLen glb) False),
    index = 0
}

setPattern :: Int -> Pattern
setPattern decimal = Pattern {
    pat0 = testBit decimal 0,
    pat1 = testBit decimal 1,
    pat2 = testBit decimal 2,
    pat3 = testBit decimal 3,
    pat4 = testBit decimal 4,
    pat5 = testBit decimal 5,
    pat6 = testBit decimal 6,
    pat7 = testBit decimal 7
}

findPattern :: Bool -> Bool -> Bool -> Pattern -> Bool
findPattern b1 b2 b3 pos = case (b1, b2, b3) of
  (False, True, True)   -> (pat0 pos)
  (False, True, False)  -> (pat1 pos)
  (False, False, True)  -> (pat2 pos)
  (True, False, False)  -> (pat3 pos)
  (True, True, True)    -> (pat4 pos)
  (True, True, False)   -> (pat5 pos)
  (True, False, True)   -> (pat6 pos)
  (False, False, False) -> (pat7 pos)

modifyValue :: Int -> Int -> Bool -> Save -> [[Bool]]
modifyValue i j newValue save = take i (saved save)
  ++ [take j (saved save !! i) ++ [newValue] ++ drop (j + 1) (saved save !! i)]
  ++ drop (i + 1) (saved save)

setFirstLine :: Glb -> Save -> [[Bool]]
setFirstLine glb save = modifyValue 0 (mid glb) True (initSave (saved save) glb)

printMap :: [[Bool]] -> IO ()
printMap grid = mapM_ putStrLn (map (map (\b -> if b then '*' else ' ')) grid)

getOpts :: Options -> [String] -> Maybe Options
getOpts opt [] = Just opt
getOpts opt (x : xs) = case x of
    "--rule" -> case xs of
        (r : rs) -> getOpts (opt {orule = readMaybe r}) rs
        [] -> Nothing
    "--start" -> case xs of (s : ss) -> getOpts (opt {ostart = read s}) ss
    "--lines" -> case xs of
        (l : ls) -> getOpts (opt {olines = readMaybe l}) ls
        [] -> Nothing
    "--windows" -> case xs of (w : ws) -> getOpts (opt {owin = read w}) ws
    "--move" -> case xs of (m : ms) -> getOpts (opt {omove = read m}) ms
    _ -> Nothing -- clause pour le cas par défaut

-- fonction errorExit
errorExit :: String -> IO ()
errorExit msg = hPutStrLn stderr msg >> exitWith (ExitFailure 84)

-- fonction applyAtPosition
applyAtPosition :: [[Bool]] -> (Int, Int) -> (Bool -> Bool -> Bool -> Pattern -> Bool) -> Bool
applyAtPosition list (x, y) f =
    let b1 = if y > 0 && x > 0 then (list !! (x-1)) !! (y-1) else False
        b2 = if y > 0 then (list !! x) !! (y-1) else False
        b3 = if y > 0 && x < length list - 1 then (list !! (x+1)) !! (y-1) else False
        p = Pattern (list !! x !! y)
                    (if y > 0 then (list !! x) !! (y-1) else False)
                    (if y < length (head list) - 1 then (list !! x) !! (y+1) else False)
                    b1
                    (if x > 0 then (list !! (x-1)) !! y else False)
                    (if x < length list - 1 then (list !! (x+1)) !! y else False)
                    (if x > 0 && y < length (head list) - 1 then (list !! (x-1)) !! (y+1) else False)
                    b3
    in f b1 b2 b3 p

updateAtPosition :: [[Bool]] -> (Int, Int) -> Bool -> [[Bool]]
updateAtPosition list (x, y) newValue =
    take x list ++
    [take y (list !! x) ++ [newValue] ++ drop (y + 1) (list !! x)] ++
    drop (x + 1) list

applyToAllPositions :: [[Bool]] -> (Bool -> Bool -> Bool -> Pattern -> Bool) -> [[Bool]]
applyToAllPositions list f =
  let positions = [(x, y) | x <- [0..length list - 1], y <- [0..length (head list) - 1]]
      emptyLists = replicate (length list) (replicate (length (head list)) False)
  in foldr (\pos acc -> updateAtPosition acc pos (applyAtPosition list pos f)) emptyLists positions

maintwo :: Options -> IO ()
maintwo options =
    let pattern = setPattern (fromJust (orule options))
        glb = Glb {mid = (1 + (fromJust (olines options)) * 2) `div` 2,
                   width = (owin options) + (omove options),
                   height = (fromJust (olines options)) + 1,
                   rowLen = (owin options) + (omove options) + 1}
        save = Save {saved = setFirstLine glb save, index = 0}
    in printMap (applyToAllPositions (saved save) (findPattern pattern))


main :: IO ()
main = do
    args <- getArgs
    case getOpts defaultOptions args of
        Just options ->
            case orule options of
                Just r -> case olines options of
                    Just l -> maintwo options
                    Nothing -> maintwo options
                Nothing -> errorExit "Invalid argument: rule not specified"
        Nothing -> errorExit "Invalid argument"