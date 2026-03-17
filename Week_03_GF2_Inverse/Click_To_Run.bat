@echo off
color 0A
echo ===========================================
echo   BAI TAP TUAN 3 - CAO QUANG HUNG
echo   MON: AN TOAN THONG TIN - CO HUE
echo ===========================================
echo.
:: Kiem tra neu file exe ton tai trong thu muc bin thi chay
if exist "bin\GF2.exe" (
    "bin\GF2.exe"
) else (
    echo [LOI] Khong tim thay file GF2.exe trong thu muc bin.
)
echo.
echo ===========================================
pause