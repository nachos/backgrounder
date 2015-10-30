{
  "targets": [
    {
      "target_name": "backgrounder",
      "sources": ["src/backgrounder_win.cpp"],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
