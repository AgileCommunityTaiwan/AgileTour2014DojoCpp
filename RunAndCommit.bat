REM usage RunAndCommit.bat"$(TargetPath)"
@echo off

git config user.name AgileCommunity.tw
git config user.email "agilecomm.tw@gmail.com"

REM run unit tests
%1
if %errorlevel%==0 goto GIT_COMMIT
goto END

:GIT_COMMIT
pushd ..

call CommitDojoCode.bat
popd
exit 0


:END
