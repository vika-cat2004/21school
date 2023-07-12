chmod 777 ai_door_management_module_sh.
cd ..
mv *.1 door_map  
mv *.log door_logs
mv *.conf door_configuration
mkdir door_map
mkdir door_logs
mkdir door_configuration
mv door_management_fi/door_management_files
chmod 777 ai_door_mcontrol_sh.
git add door_management_files
git commit -m "config" 
git push