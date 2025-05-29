-- [nfnl] ftdetect/actions.fnl
local function _1_()
  _G.vim.bo.filetype = "actions"
  return nil
end
return _G.vim.api.nvim_create_autocmd({"BufRead", "BufNewFile"}, {pattern = "*.actions", callback = _1_})
