@echo off
color 0B
echo ===========================================
echo   BAI TAP TUAN 1 - CAO QUANG HUNG
echo   THUAT TOAN: PLAYFAIR CIPHER
echo ===========================================
echo.
:: Kiem tra file exe trong thu muc bin
if exist "bin\playfair_cipher.exe" (
    "bin\playfair_cipher.exe"
) else (
    echo [LOI] Khong tim thay file playfair_cipher.exe trong thu muc bin.
)
echo.
echo ===========================================
pause