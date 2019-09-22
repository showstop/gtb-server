wave common_def.dc auth.dc internal_log.dc internal_as_ls.dc lobby.dc player.dc vehicle.dc ability.dc internal_ls_mms.dc internal_ls_ps.dc internal_ls_ls.dc internal_resource_report.dc grandprix.dc achievement.dc attendance.dc daily_mission.dc reward_station.dc dev_test.dc
  
wave --t cs common_def.dc auth.dc lobby.dc player.dc vehicle.dc ability.dc internal_resource_report.dc grandprix.dc achievement.dc attendance.dc daily_mission.dc reward_station.dc dev_test.dc internal_ls_ps.dc

@echo off
del ..\*.h
del ..\*.cpp
del ..\*.cs

move *.h ..\ 
move *.cpp ..\ 
move *.cs ..\

copy ..\*.cs ..\..\..\client\Assets\Script\Network\protocol

@pause
