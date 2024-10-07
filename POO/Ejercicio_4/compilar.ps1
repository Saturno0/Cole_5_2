#ps1
param(
	[string] $fuentecpp = ".\Sudoku.cpp"
)

remove-item .\Main.exe
Start-Process g++ -ArgumentList "${fuentecpp} -o Main" -NoNewWindow
sleep 1
start-process .\Main.exe
