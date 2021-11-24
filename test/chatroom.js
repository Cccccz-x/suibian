(function(){
    function handleLogin() {
        // 拿到登录信息
        var userName = document.querySelector('.usrName input').value
        var userPassword = document.querySelector('.usrPwd input').value
        alert('用户'+userName+'登陆成功')
        showChatRoom()
    }
    function showChatRoom() {
        // 隐藏登录框，展示聊天框
        var login = document.querySelector('.login')
        var chatRoom = document.querySelector('.chatRoom')
        login.style.top = '-100%'
        chatRoom.style.top = '0'
    }
    var loginButton = document.querySelector('.login-button')
    loginButton.addEventListener('click', function(e) {
        handleLogin()
    }, false)

    function sendMsg() {
        var msg = document.querySelector('.input-wrap .input').value

        var msgBox = document.createElement('div')
        msgBox.setAttribute('class', 'msg msg-me')

        var avatar = document.createElement('img')
        avatar.src = './me.png'
        avatar.setAttribute('class', 'avatar')

        var msgTxt = document.createElement('div')
        msgTxt.setAttribute('class', 'msg-txt')
        msgTxt.innerHTML = msg

        msgBox.appendChild(avatar)
        msgBox.appendChild(msgTxt)
        var msgList = document.querySelector('.msg-wrap')
        msgList.appendChild(msgBox)
        clearBox()
    }

    function clearBox() {
        var input = document.querySelector('.input-wrap .input')
        input.value = ""
    }

    var sendButton = document.querySelector('.input-wrap button')
    sendButton.addEventListener('click', function(e) {
        sendMsg()
    }, false)

})()