while ($i -lt 1000){
    Add-Content -Path C:\Users\hanhnguyen26\countProcess.txt -Value (Get-Process).Count
    Start-Sleep -Seconds 2
    $i++;
}