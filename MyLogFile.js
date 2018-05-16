// require("js/omv/grid/column/WhiteSpace.js")
// require("js/omv/module/admin/diagnostic/log/plugin/Plugin.js")

Ext.define("OMV.module.admin.diagnostic.log.plugin.tvheadend", {
    extend : "OMV.module.admin.diagnostic.log.plugin.Plugin",
    alias  : "omv.plugin.diagnostic.log.tvheadend",

    id       : "tvheadend",
    text     : _("TvHeadend"),
    stateful : true,
    stateId  : "bcaee373-3d64-481b-b921-5264064634b3",
    columns  : [{
        text      : _("Date & Time"),
        sortable  : true,
        dataIndex : "date",
        stateId   : "date",
        renderer  : OMV.util.Format.localeTimeRenderer()
    },{
        text      : _("Type"),
        sortable  : true,
        dataIndex : "type",
        stateId   : "type",
        flex      : 1
    },{
        text      : _("Log"),
        sortable  : true,
        dataIndex : "log",
        stateId   : "log",
        flex      : 1
    }],
    rpcParams : {
        id : "tv"
    },
    rpcFields : [
        { name : "date", type : "string" },
        { name : "type", type : "string" },
        { name : "log", type : "string" }
    ]
});
