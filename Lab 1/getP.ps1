while ($true){
	Add-Content -Path C:\Users\hanhnguyen26\countProcess.txt -Value (Get-Process).Count
	Start-Sleep -Second 2
	}