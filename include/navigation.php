<?php
echo "
<div class='nav-bar'>
	";
	if(session_id()=="")
		session_start();
	if(isset($_SESSION['username']) && isset($_SESSION['type']))
	{
		$username=$_SESSION['username'];
		echo "
		<a href='user.php?user=$username'>$username</a>
		<a href='functions/logout.php'>Logout</a>
		";
	}
	echo '
</div>';
?>
