use trajoptlib::{SwerveDrivetrain, SwerveModule, SwervePathBuilder};

fn main() {
    let drivetrain = SwerveDrivetrain {
        mass: 45.0,
        moi: 6.0,
        modules: vec![
            SwerveModule {
                x: 0.6,
                y: 0.6,
                wheel_radius: 0.04,
                wheel_max_angular_velocity: 70.0,
                wheel_max_torque: 2.0,
            },
            SwerveModule {
                x: 0.6,
                y: -0.6,
                wheel_radius: 0.04,
                wheel_max_angular_velocity: 70.0,
                wheel_max_torque: 2.0,
            },
            SwerveModule {
                x: -0.6,
                y: 0.6,
                wheel_radius: 0.04,
                wheel_max_angular_velocity: 70.0,
                wheel_max_torque: 2.0,
            },
            SwerveModule {
                x: -0.6,
                y: -0.6,
                wheel_radius: 0.04,
                wheel_max_angular_velocity: 70.0,
                wheel_max_torque: 2.0,
            },
        ],
    };

    let mut path = SwervePathBuilder::new();
    path.set_drivetrain(&drivetrain);
    path.set_bumpers(1.3, 1.3);
    path.pose_wpt(0, 0.0, 0.0, 0.0);
    path.pose_wpt(1, 1.0, 0.0, 0.0);
    // path.wpt_linear_velocity_polar(0, 0.0, 0.0);
    // path.wpt_linear_velocity_polar(1, 0.0, 0.0);
    // path.wpt_angular_velocity(0, 0.0);
    // path.wpt_angular_velocity(1, 0.0);
    // path.sgmt_circle_obstacle(0, 1, 0.5, 0.1, 0.2);
    path.set_control_interval_counts(vec![40]);
    println!("setup complete");
    println!("{:?}", path.generate());
}
