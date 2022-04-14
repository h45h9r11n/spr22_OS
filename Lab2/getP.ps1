while ($true){
	$freemem = Get-WmiObject -Class Win32_OperatingSystem
	Add-Content -Path .\mem.txt -Value $freemem.FreePhysicalMemory
	Start-Sleep -Second 2
}

