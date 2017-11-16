# omv-log
If you want to display additional custom log files in the WebGUI at 'Diagnostics | System Logs' then you have to do the following.
Create a file called 99mylogspecs.inc in /usr/share/openmediavault/engined/inc. Here you can add your log file specifications.

The description of the structure can be found here: 

https://github.com/openmediavault/openmediavault/blob/master/deb/openmediavault/usr/share/php/openmediavault/system/logfilespec.inc

The first argument of the registerSpecification must be a unique identifier. 
This must be used later in the JavaScript code, too.
To take your changes into action you simply have to restart the OMV engine.

-> monit restart omv-engined

During development you should manually start the engine to see if there are any errors. They will be displayed immediatelly.

-> omv-engined -d -f

To display the log file in the WebUI, you have to add a JavaScript file at 
/var/www/openmediavault/js/omv/module/admin/diagnostic/log/plugin

The name of the JavaScript class must be unique. By default it is the same name as used in the registerSpecification method above. 
The same name must be defined for the id and rpcParams.id attributes. The stateId attribute must be an unique UUIDv4. 
The rpcFields attribue describes the log data that is returned by the RPC. The columns attribute is an array of columns to be displayed.
The Sencha ExtJS API can be found here:
http://docs.sencha.com/extjs/5.1.1/api/Ext.html

THX to votdev at omv-forum
