@echo off
color 0D
echo ===========================================
echo   BAI TAP TUAN 4 - CAO QUANG HUNG
echo   THUAT TOAN: MA HOA DONG RC4
echo ===========================================
echo.
:: Kiem tra file exe trong thu muc bin
if exist "bin\rc4_demo.exe" (
    "bin\rc4_demo.exe"
) else (
    echo [LOI] Khong tim thay file rc4_demo.exe trong thu muc bin.
)
echo.
echo ===========================================
pause